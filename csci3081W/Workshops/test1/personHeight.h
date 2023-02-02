class personHeight
{
private:
    int feet;
    double inches;
public:
    personHeight(int, double);
    double height_in_inches();
};

double personHeight::height_in_inches(){
    return (12 * this->feet) + this->inches;
}

personHeight::personHeight(int feet = 0, double inches = 0.0){
    this->feet = feet;
    this->inches = inches;
}

