#include "game.h"
#include <iostream>
#include "SDL.h"
#include "food.h"

Game::Game(std::size_t grid_width, std::size_t grid_height, std::string name)
    : snake(name, grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x_pos = x;
      food.y_pos = y;
      break;
    }
  }

  // internal random number generator
    std::random_device rd;     
    std::mt19937 rng(rd());    
    std::uniform_int_distribution<int> ud(1,3); 
    int randomNum = ud(rng); // a Random number between 1 and 4 is generated

  // change food type according to number generated
    if(randomNum == 1){
      std::vector<int> v = {124,252,0}; // rgb values for the colour green
      food.SetColour(std::move(v));
      food.SetFoodValue(2);
      food.SetType("Super");
    }
    else{
      std::vector<int> v = {255,255,0}; // rgb values for the colour yellow
      food.SetColour(std::move(v));
      food.SetFoodValue(1);
      food.SetType("Normal");
    }

    
}

void Game::Update() {
  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x_pos == new_x && food.y_pos == new_y) {
    score += food.GetFoodValue();
    std::cout << snake.GetName() << " has eaten " << food.GetType() << " food\n";
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }