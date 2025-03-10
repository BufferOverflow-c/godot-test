#ifndef MAIN_H
#define MAIN_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/classes/timer.hpp>

namespace brain {

class Main : public godot::Node {
  GDCLASS(Main, godot::Node)
public:
  Main();
  ~Main();

  void _ready() override;
  void _process(const double delta) override;

  // GETTERS
  godot::Ref<godot::PackedScene> get_mob_scene() { return mob_scene; }
  int get_score() const { return score; }

  // SETTERS
  void set_mob_scene(godot::Ref<godot::PackedScene> p_mob_scene) { mob_scene = p_mob_scene; }
  void set_score(const int p_score) { ++score; }

protected:
  static void _bind_methods();
  void start_timer_end();

private:
  godot::Timer *start_timer{nullptr};
  godot::Ref<godot::PackedScene> mob_scene{nullptr};
  int score{};
};

}

#endif
