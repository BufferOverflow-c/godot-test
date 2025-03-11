#ifndef MOB_H
#define MOB_H

#include <godot_cpp/classes/animated_sprite2d.hpp>
#include <godot_cpp/classes/random_number_generator.hpp>
#include <godot_cpp/classes/rigid_body2d.hpp>
#include <godot_cpp/classes/visible_on_screen_notifier2d.hpp>
#include <godot_cpp/variant/packed_string_array.hpp>
namespace godot {

class Mob : public RigidBody2D {
  GDCLASS(Mob, RigidBody2D)
public:
  Mob();
  ~Mob();

  // OVERRIDES
  void _ready() override;

protected:
private:
  Vector2 position{};
  AnimatedSprite2D *animatedSprite2D;
  VisibleOnScreenNotifier2D *notifier2D;
  PackedStringArray mobTypes{};
  RandomNumberGenerator rng;
};

} // namespace godot

#endif
