#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_sprite_ptr.h>
#include <bn_random.h>
#include <bn_vector.h>
#include <bn_keypad.h>

#include "bn_sprite_items_bug.h"



int main(){
    bn::core::init();

    bn::random rng = bn::random();

    bn::backdrop::set_color(bn::color(16,16,31));

    bn::vector<bn::sprite_ptr, 50> bugs = {};

    //bn::sprite_ptr bug = bn::sprite_items::bug.create_sprite();

    while(true){
        for(bn::sprite_ptr& bug: bugs){
            bn::fixed new_x = bug.x() + rng.get_fixed(-1, 1);
            bn::fixed new_y = bug.y() + rng.get_fixed(-1, 1);
            bug.set_position(new_x, new_y);
        }
        

        if (bn::keypad::a_pressed()){
            bugs.push_back(bn::sprite_items::bug.create_sprite());
        }

        rng.update();
        bn::core::update();
        
    }
}