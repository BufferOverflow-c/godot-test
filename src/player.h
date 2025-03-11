#ifndef PLAYER_H
#define PLAYER_H

#include <godot_cpp/classes/animated_sprite2d.hpp>
#include <godot_cpp/classes/area2d.hpp>
#include <godot_cpp/classes/collision_shape2d.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/physics_body2d.hpp>
namespace godot {

class Player : public Area2D {
  GDCLASS(Player, Area2D)
public:
  Player();
  ~Player();

  // OVERRIDES
  void _ready() override;
  void _process(const double delta) override;
  void _on_body_entered(Node2D *body);

  void start(Vector2 position);

  // GETTERS
  double get_speed() const;
  // SETTERS
  void set_speed(const double p_speed);

protected:
  static void _bind_methods();
  void movement();
  void updateAnimation();
  void updatePosition(const double delta);

private:
  CollisionShape2D *collisionShape2D{nullptr};
  AnimatedSprite2D *animatedSprite2D{nullptr};
  double speed{};
  Vector2 screenSize{};
  Vector2 velocity{};
  Vector2 position{};
};

} // namespace godot

#endif // !PLAYER_H
