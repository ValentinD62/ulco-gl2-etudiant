#pragma once
#include <math.h>

class Forme {
    public:
        virtual ~Forme() = default;
        virtual double aire() const = 0;
};

class Disque : public Forme {
    private:
        double _rayon;
    public:
        Disque(double rayon);

        double aire()const override{
            return M_PI * (_rayon * _rayon);
        }

        //const Description & to Description(){}

};

class Rectangle : public Forme {
    private :
        double _largeur;
        double _hauteur;
    public:
        Rectangle(double largeur, double hauteur);
        
        double aire() const override{
            return _largeur * _hauteur;
        }

        //const Description & to Description(){}
};