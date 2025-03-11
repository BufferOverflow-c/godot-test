#ifndef MAIN_H
#define MAIN_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/classes/timer.hpp>

using namespace godot;

class Main : public Node {
  GDCLASS(Main, Node)
public:
  Main();
  ~Main();

  void _ready() override;

  // GETTERS
  Ref<PackedScene> get_mob_scene() { return mob_scene; }
  int get_score() const { return score; }

  // SETTERS
  void set_mob_scene(Ref<PackedScene> p_mob_scene) { mob_scene = p_mob_scene; }
  void set_score(const int p_score) { ++score; }

protected:
  static void _bind_methods();
  void start_timer_end();

private:
  Timer *start_timer{nullptr};
  Ref<PackedScene> mob_scene{nullptr};
  int score{};
};

#endif
