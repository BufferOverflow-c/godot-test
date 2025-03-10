#include "main.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace brain;
using namespace godot;

Main::Main() { 
  score = 0;
}

Main::~Main() {
}

void Main::_ready() {
  start_timer = memnew(Timer);
  // start_timer = get_node<Timer>("StartTimer");
  add_child(start_timer);
  start_timer->connect("timeout", Callable(this, "start_timer_ended"));
  start_timer->set_wait_time(2.0);
  start_timer->set_one_shot(true);
  start_timer->set_autostart(true);
  start_timer->start();
}

void Main::_process(const double delta) {
  // start_timer->emit_signal("_on_start_timer_timeout");
}

void Main::start_timer_end() {
  UtilityFunctions::print("timer ended");
  set_score(1);
}

void Main::_bind_methods() {
  ClassDB::bind_method(D_METHOD("get_mob_scene"), &Main::get_mob_scene);
  ClassDB::bind_method(D_METHOD("set_mob_scene", "p_mob_scene"), &Main::set_mob_scene);

  ClassDB::bind_method(D_METHOD("get_score"), &Main::get_score);
  ClassDB::bind_method(D_METHOD("set_score", "p_score"), &Main::set_score);
  
  ClassDB::bind_method(D_METHOD("start_timer_end"), &Main::start_timer_end);

  ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "Mob_Scene", PROPERTY_HINT_RESOURCE_TYPE, "PackedScene"), "set_mob_scene", "get_mob_scene");
  ADD_PROPERTY(PropertyInfo(Variant::INT, "Score"), "set_score", "get_score");
}


