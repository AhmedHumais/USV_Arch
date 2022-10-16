#include "HEAR_control/Template.hpp"

namespace HEAR {

Template::Template(int b_uid) : Block(BLOCK_ID::TEMPLATE, b_uid){
    _out = createOutputPort<float>(OP::OUT, "output");
    _in = createInputPort<float>(IP::INP, "Input");
    // your code
}

void Template::process(){
    float x;
    _in->read(x);
    _out->write(x*XYZ);
    std::cout << "Template Block called \n";
}

void Template::update(UpdateMsg* u_msg){
    if(u_msg->getType() == TEMPLATE_MSG){
        XYZ = ((TemplateMsg*)u_msg)->param;
    }
}

}