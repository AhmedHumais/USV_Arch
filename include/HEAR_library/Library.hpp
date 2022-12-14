#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "HEAR_core/Block.hpp"
#include "HEAR_core/Vector3D.hpp"

#include "HEAR_control/BWFilter.hpp"
#include "HEAR_control/Constant.hpp"
#include "HEAR_control/Demux3.hpp"
#include "HEAR_control/Differentiator.hpp"
#include "HEAR_control/FoH.hpp"
#include "HEAR_control/Gain.hpp"
#include "HEAR_control/HoldVal.hpp"
#include "HEAR_control/InvertedSwitch.hpp"
#include "HEAR_control/InvertedSwitch3.hpp"
#include "HEAR_control/MedianFilter.hpp"
#include "HEAR_control/Multiply.hpp"
#include "HEAR_control/Mux3.hpp"
#include "HEAR_control/Saturation.hpp"
#include "HEAR_control/Sum.hpp"
#include "HEAR_control/Sum3.hpp"
#include "HEAR_control/Switch.hpp"
#include "HEAR_control/Template.hpp"

#include <iostream>


namespace HEAR
{

class Library {
    public :
    static Block* createBlock(BLOCK_ID b_type, int b_uid, double _dt = 0, TYPE d_type=TYPE::NA);
};

Block* Library::createBlock(BLOCK_ID b_type, int b_uid, double _dt, TYPE d_type){
    Block* blk;
    switch (b_type)
    {
    case BLOCK_ID::BW_FILT2 :
        if(d_type == TYPE::Float3){
            blk = new BWFilter2<Vector3D<float>>(b_uid);
        }
        else{
            blk = new BWFilter2<float>(b_uid);
        }
        break;
    case BLOCK_ID::CONSTANT :
        if(d_type == TYPE::Float3){
            blk = new Constant<Vector3D<float>>(b_uid);
        }
        else{
            blk = new Constant<float>(b_uid);
        }
        break;
    case BLOCK_ID::DEMUX3 :
        blk = new Demux3(b_uid);
        break;
    case BLOCK_ID::DIFFERENTIATOR :
        if(d_type == TYPE::Float3){
            blk = new Differentiator<Vector3D<float>>(_dt, b_uid);
        }
        else{
            blk = new Differentiator<float>(_dt, b_uid);
        }
        break;
    case BLOCK_ID::FOH :
        if(d_type == TYPE::Float3){
            blk = new FoH<Vector3D<float>>(_dt, b_uid);
        }
        else{
            blk = new FoH<float>(_dt, b_uid);
        }
        break;
    case BLOCK_ID::GAIN :
        blk = new Gain(b_uid);
        break;
    case BLOCK_ID::HOLDVAL :
        blk = new HoldVal(b_uid);
        break;
    case BLOCK_ID::INVERTED_SWITCH :
        blk = new InvertedSwitch(b_uid);
        break;
    case BLOCK_ID::INVERTED_SWITCH3 :
        blk = new InvertedSwitch3(b_uid);
        break;
    case BLOCK_ID::MEDIAN_FILTER :
        blk = new MedianFilter(b_uid);
        break;
    case BLOCK_ID::MULTIPLY :
        blk = new Multiply(b_uid);
        break;
    case BLOCK_ID::MUX3 :
        blk = new Mux3(b_uid);
        break;
    case BLOCK_ID::SATURATION :
        blk = new Saturation(b_uid);
        break;
    case BLOCK_ID::SUM :
        blk = new Sum(b_uid);
        break;
    case BLOCK_ID::SUM3 :
        blk = new Sum3(b_uid);
        break;
    case BLOCK_ID::SWITCH :
        blk = new Switch(b_uid);
        break;
    case BLOCK_ID::TEMPLATE :
        blk = new Template(b_uid);
        break;
    default:
        std::cout << "Invalid BlockID \n";
        return NULL;
    }
    return blk;
}

}

#endif