#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {

class GDExample : public Sprite2D {
  GDCLASS(GDExample, Sprite2D)

private:
  double time_passed;
  double amplitude;
  double speed;
  time_t time_emit;

protected:
  static void _bind_methods();

public:
  GDExample();
  ~GDExample();

  void _process(double delta) override;
  // SETTERS
  void set_amplitude(const double p_amplitude);
  void set_speed(const double p_speed);
  // GETTERS
  double get_amplitude() const;
  double get_speed() const;
};

} // namespace godot

#endif
