#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include "HEAR_core/Block.hpp"

namespace HEAR{

class Template :public Block {
private:
    OutputPort<float>* _out;
    InputPort<float>* _in;
    float XYZ =0;
public:
    enum OP{OUT};
    enum IP{INP};
    Template(int b_uid);
    ~Template(){}
    void process();
    void update(UpdateMsg* u_msg) override;

};

}

#endif