#include "player.h"
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/input_map.hpp>
#include <godot_cpp/classes/shape2d.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/core/class_db.hpp>
using namespace godot;

Player::Player() {
  animatedSprite2D = nullptr;
  collisionShape2D = nullptr;
  speed = 400.0;
  position = {240, 360};
}

Player::~Player() {
  // Add cleanup
  collisionShape2D = nullptr;
  animatedSprite2D = nullptr;
  delete collisionShape2D;
  delete animatedSprite2D;
}

void Player::_ready() {
  collisionShape2D = get_node<CollisionShape2D>("CollisionShape2D");
  set_position(position);
  InputMap::get_singleton()->load_from_project_settings();
  animatedSprite2D = get_node<AnimatedSprite2D>("AnimatedSprite2D");
  screenSize = get_viewport()->get_visible_rect().size;
  hide();
}

void Player::_process(const double delta) {
  velocity = {};
  animatedSprite2D = get_node<AnimatedSprite2D>("AnimatedSprite2D");
  movement();
  updateAnimation();
  updatePosition(delta);
}

void Player::movement() {
  if (Input::get_singleton()->is_action_pressed("move_right")) {
    velocity.x += 1;
  }
  if (Input::get_singleton()->is_action_pressed("move_left")) {
    velocity.x -= 1;
  }
  if (Input::get_singleton()->is_action_pressed("move_down")) {
    velocity.y += 1;
  }
  if (Input::get_singleton()->is_action_pressed("move_up")) {
    velocity.y -= 1;
  }
}

void Player::updateAnimation() {
  if (velocity.length() > 0) {
    velocity = velocity.normalized() * speed;
    animatedSprite2D->play();
  } else {
    animatedSprite2D->stop();
  }

  if (velocity.x != 0) {
    animatedSprite2D->set_animation("walk");
  } else if (velocity.y != 0) {
    animatedSprite2D->set_animation("up");
  }
  animatedSprite2D->set_flip_h(velocity.x < 0);
  animatedSprite2D->set_flip_v(velocity.y > 0);
}

void Player::updatePosition(const double delta) {
  Size2 hitBox{collisionShape2D->get_shape()->get_rect().size};
  position += velocity * static_cast<float>(delta);
  position = Vector2(
      Math::clamp(position.x, 0.f + hitBox.x / 2, screenSize.x - hitBox.x / 2),
      Math::clamp(position.y, 0.f + hitBox.y / 2, screenSize.y - hitBox.y / 2));
  set_position(position);
}

void Player::start(Vector2 position) {
  set_position(position);
  show();
  collisionShape2D->set_disabled(false);
}

/*void Player::_on_body_entered(Node2D *body) {*/
/*  hide();*/
/*  emit_signal("hit_event", this, body);*/
/*  collisionShape2D->set_disabled(true);*/
/*}*/

double Player::get_speed() const { return speed; }

void Player::set_speed(const double p_speed) { speed = p_speed; }

void Player::_bind_methods() {
  ClassDB::bind_method(D_METHOD("get_speed"), &Player::get_speed);
  ClassDB::bind_method(D_METHOD("set_speed", "p_speed"), &Player::set_speed);

  ADD_PROPERTY(
      PropertyInfo(Variant::FLOAT, "speed", PROPERTY_HINT_RANGE, "0,1000,1"),
      "set_speed", "get_speed");

  ADD_SIGNAL(MethodInfo("hit_event", PropertyInfo(Variant::OBJECT, "Area2D"),
                        PropertyInfo(Variant::NODE_PATH, "Node2D")));
}
