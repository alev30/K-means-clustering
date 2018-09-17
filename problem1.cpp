#include <iostream>
#include <cmath>
#include <vector>


class datapoint{
    private:
        char point_id;
        double x;
        double y;
        double cent_dist1;
        double cent_dist2;
    public:
        datapoint(char ID,double x, double y, double cent_dist1 = 0, double cent_dist2 = 0) 
            : point_id(ID), x(x), y(y){}
        void cent1distformula(double cent1x, double cent1y){
            cent_dist1 = pow( (  pow( (x- cent1x) , 2 ) + pow ( (y - cent1y) , 2)  )  , 0.5);
        }
        void cent2distformula(double cent2x, double cent2y){
            cent_dist2 = pow( (  pow( (x- cent2x) , 2 ) + pow ( (y - cent2y) , 2)  )  , 0.5);
        }
        double getx(){
            return x;
        }
        double gety(){
            return y;
        }
        double getcent1dist(){
            return cent_dist1;
        }
        double getcent2dist(){
            return cent_dist2;
        }
        char getLabel(){
            return point_id;
        }
};




int main(){
    std::vector <datapoint> startingset;
    startingset.push_back(datapoint('A',5,36));
    startingset.push_back(datapoint('B',73,78));
    startingset.push_back(datapoint('C',34,61));
    startingset.push_back(datapoint('D',86,33));
    startingset.push_back(datapoint('E',67,24));
    startingset.push_back(datapoint('F',20,16));
    startingset.push_back(datapoint('G',73,14));
    startingset.push_back(datapoint('H',5,88));
    startingset.push_back(datapoint('I',27,93));
    startingset.push_back(datapoint('J',30,21));
    startingset.push_back(datapoint('K',51,41));
    startingset.push_back(datapoint('L',3,59));

    double cent1x = 73;
    double cent1y = 78;
    double cent2x = 34;
    double cent2y = 61;

    double x1post = 0;
    double y1post = 0;
    double x2post = 0;
    double y2post = 0;

    double set1_x_meandiff;
    double set1_y_meandiff;
    double set2_x_meandiff;
    double set2_y_meandiff;

    int counter = 0;


    std::vector <datapoint> set_1;
    std::vector <datapoint> set_2;

    bool ran_once = false;

    do {
        if (ran_once == true){
            cent1x = x1post;
            cent1y = y1post;
            cent2x = x2post;
            cent2y = y2post;
        }

        std::cout << "The k means clustered coordinates of centroid one iteration " << counter << "are x: " << cent1x << " y: " << cent1y << std::endl;
        std::cout << "The k means clustered coordinates of centroid two iteration " << counter << "are x: " << cent2x << " y: " << cent2y << std::endl;

        counter ++;
        set_1.clear();
        set_2.clear();
        for (int i  = 0; i <  12; i++){
            startingset[i].cent1distformula(cent1x,cent1y);
            startingset[i].cent2distformula(cent2x,cent2y);


            std::cout<< "Label: " << startingset[i].getLabel() << "| distance from point1: " << startingset[i].getcent1dist() <<
                " | distance from point 2: " << startingset[i].getcent2dist() << std::endl;

            //std::cout << "distance"<< startingset[i].getcent1dist() << "distance2" << startingset[i].getcent2dist() <<std::endl;

            if (startingset[i].getcent1dist() <= startingset[i].getcent2dist()){
                set_1.push_back(startingset[i]);
            }
            else{
                set_2.push_back(startingset[i]);
            }
        }

        x1post = 0;
        y1post = 0;
        y2post = 0;
        x2post = 0;

        for (int i = 0; i <  (short) set_1.size(); i++){
            x1post += set_1[i].getx();
            y1post += set_1[i].gety();
        }
        x1post /= set_1.size();
        y1post /= set_1.size();


        for (int i = 0; i <  (short) set_2.size(); i++){
            x2post += set_2[i].getx();
            y2post += set_2[i].gety();
        }
        x2post /= set_2.size();
        y2post /= set_2.size();
        
        set1_x_meandiff = abs(cent1x - x1post);
        set1_y_meandiff = abs(cent1y - y1post);

        set2_x_meandiff = abs(cent2x - x2post);
        set2_y_meandiff = abs(cent2y - y2post);

        ran_once = true;


    } while ( set1_x_meandiff > 0.1 ||  set1_y_meandiff > 0.1 || set2_x_meandiff > 0.1 ||  set2_y_meandiff > 0.1);


    std::cout << "The k means clustered coordinates of centroid one are x: " << x1post << " y: " << y1post << std::endl;
    std::cout << "The k means clustered coordinates of centroid two are x: " << x2post << " y: " << y2post << std::endl;

    std::cout << "counter: " << counter << std::endl;


    return 0;
 }


//