#include "HEAR_core/System.hpp"
#include "HEAR_control/Template.hpp"

#include <chrono>
#include <thread>

using namespace HEAR;

int main(int argc, char** argv){
    auto sys = new System(1, "Test System");

    auto constant = sys->createBlock(BLOCK_ID::CONSTANT, "Constant", TYPE::Float);
    ((Constant<float>*)constant)->setValue(0.4);

    // auto temp = new Template(0);
    // sys->addBlock(temp, "Template");
    auto temp = sys->createBlock(BLOCK_ID::TEMPLATE, "Template");

    sys->connect(constant->getOutputPort<float>(Constant<float>::OP::OUTPUT), temp->getInputPort<float>(Template::IP::INP));

    sys->init(true);

    while(1){
        sys->loop();
        std::this_thread::sleep_for(std::chrono::microseconds((int)(sys->_dt*1e6)));
    }

}