#include "mob.h"

#include <godot_cpp/classes/sprite_frames.hpp>
#include <godot_cpp/core/class_db.hpp>

// std
#include <ctime>

using namespace godot;

Mob::Mob() { position = {}; }

Mob::~Mob() {
  delete animatedSprite2D;
  animatedSprite2D = nullptr;
}

void Mob::_ready() {
  rng.set_seed(time(nullptr));
  animatedSprite2D = get_node<AnimatedSprite2D>("AnimatedSprite2D");
  mobTypes = animatedSprite2D->get_sprite_frames()->get_animation_names();
  animatedSprite2D->play(mobTypes[rng.randi() % 3]);
  ;
  if (!notifier2D->is_on_screen()) {
    queue_free();
  }
}
