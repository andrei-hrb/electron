#include "Electronic Components/Switches/Switch_SPDT.h"

Helper Switch_SPDT_Helper;

Switch_SPDT::Switch_SPDT(): ElectronicComponent(200, 50, "SPDT Switch", 3){}

//Drawing the component:
void Switch_SPDT::Show(){
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    Switch_SPDT_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    Switch_SPDT_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y, center_x - thisHeight / 2 - thisHeight / 10, center_y, getPositionCenter(),
        rotateState);

    Switch_SPDT_Helper.rotationalCircle(
        center_x - thisHeight / 2, center_y, getPositionCenter(), height / 10,
        rotateState);

    Switch_SPDT_Helper.rotationalLine(
        center_x - thisHeight / 2 + thisHeight / 13, center_y - height / 25, center_x + thisHeight / 2 - thisHeight / 13, up_left_y + height / 10 + height / 25, getPositionCenter(),
        rotateState);

    Switch_SPDT_Helper.rotationalCircle(
        center_x + thisHeight / 2, up_left_y + height / 10, getPositionCenter(), height / 10,
        rotateState);

    Switch_SPDT_Helper.rotationalLine(
        center_x + thisHeight / 2 + thisHeight / 10, up_left_y + height / 10, down_right_x - thisHeight / 5, up_left_y + height / 10, getPositionCenter(),
        rotateState);

    Switch_SPDT_Helper.rotationalCircle(
        down_right_x - thisHeight / 10, up_left_y + height / 10, getPositionCenter(), height / 10,
        rotateState);

    Switch_SPDT_Helper.rotationalCircle(
        center_x + thisHeight / 2, down_right_y - height / 10, getPositionCenter(), height / 10,
        rotateState);

    Switch_SPDT_Helper.rotationalLine(
        center_x + thisHeight / 2 + thisHeight / 10, down_right_y - height / 10, down_right_x - thisHeight / 5, down_right_y - height / 10, getPositionCenter(),
        rotateState);

    Switch_SPDT_Helper.rotationalCircle(
        down_right_x - thisHeight / 10, down_right_y - height / 10, getPositionCenter(), height / 10,
        rotateState);

    showElements();
}

void Switch_SPDT::updateConnectionPointsPosition(){

    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped){
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    connectionPoints[0].position = Switch_SPDT_Helper.rotatePointToReference(
        Switch_SPDT_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y),
        getPositionCenter(),
        rotateState);

    connectionPoints[1].position = Switch_SPDT_Helper.rotatePointToReference(
        Switch_SPDT_Helper.makeVector_2D(down_right_x - thisHeight / 10, up_left_y + height / 10),
        getPositionCenter(),
        rotateState);

    connectionPoints[2].position = Switch_SPDT_Helper.rotatePointToReference(
        Switch_SPDT_Helper.makeVector_2D(down_right_x - thisHeight / 10, down_right_y - height / 10),
        getPositionCenter(),
        rotateState);
}
