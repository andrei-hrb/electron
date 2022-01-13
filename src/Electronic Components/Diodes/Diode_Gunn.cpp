#include "Electronic Components/Diodes/Diode_Gunn.h"

Helper Diode_Gunn_Helper;

Diode_Gunn::Diode_Gunn(): ElectronicComponent(200, 50, "Gunn Diode", 2) {}

//Drawing the component:
void Diode_Gunn::Show()
{
    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped)
    {
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    Diode_Gunn_Helper.rotationalCircle(
        up_left_x + thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    Diode_Gunn_Helper.rotationalLine(
        up_left_x + thisHeight / 5, center_y, center_x - thisHeight, center_y, getPositionCenter(),
        rotateState);

    Diode_Gunn_Helper.rotationalLine(
        center_x - thisHeight, up_left_y, center_x - thisHeight, down_right_y, getPositionCenter(),
        rotateState);

    Diode_Gunn_Helper.rotationalLine(
        center_x - thisHeight, up_left_y, center_x + thisHeight, down_right_y, getPositionCenter(),
        rotateState);

    Diode_Gunn_Helper.rotationalLine(
        center_x - thisHeight, down_right_y, center_x + thisHeight, up_left_y, getPositionCenter(),
        rotateState);

    Diode_Gunn_Helper.rotationalLine(
        center_x + thisHeight, up_left_y, center_x + thisHeight, down_right_y, getPositionCenter(),
        rotateState);

    Diode_Gunn_Helper.rotationalLine(
        center_x + thisHeight, center_y, down_right_x - thisHeight / 5, center_y, getPositionCenter(),
        rotateState);

    Diode_Gunn_Helper.rotationalCircle(
        down_right_x - thisHeight / 10, center_y, getPositionCenter(), height / 10,
        rotateState);

    showElements();
}

void Diode_Gunn::updateConnectionPointsPosition()
{

    double up_left_x = getPositionUpLeft().x, up_left_y = getPositionUpLeft().y;
    double center_x = getPositionCenter().x, center_y = getPositionCenter().y;
    double down_right_x = getPositionDownRight().x, down_right_y = getPositionDownRight().y;

    if(flipped)
    {
        up_left_x = getPositionDownRight().x;
        down_right_x = getPositionUpLeft().x;
    }

    double thisHeight = (down_right_x - up_left_x) / width_height_ratio;

    connectionPoints[0].position = Diode_Gunn_Helper.rotatePointToReference(
                                       Diode_Gunn_Helper.makeVector_2D(up_left_x + thisHeight / 10, center_y),
                                       getPositionCenter(),
                                       rotateState);

    connectionPoints[1].position = Diode_Gunn_Helper.rotatePointToReference(
                                       Diode_Gunn_Helper.makeVector_2D(down_right_x - thisHeight / 10, center_y),
                                       getPositionCenter(),
                                       rotateState);
}
