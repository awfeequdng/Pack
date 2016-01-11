/*
 * File:   Item.h
 * Author: arash
 *
 * Created on June 14, 2012, 1:16 PM
 */

#ifndef ITEM_H
#define	ITEM_H
using namespace std;

struct item_build_instructions;

class Item : public virtual Shape2D
{
public:
    Item();
    Item(const Item& orig);
    virtual ~Item();

    int RotationConstraints();
    int PositionConstraints();
    void set_constraints( int value );
    void setBin( int id )
    {
        myBinProgID = id;
    }
    int getBin() { return myBinProgID; }

    /** Spin around axis

    Only makes sense for 3D items
    */
    virtual void Spin( int axis ) { }

    /** true if spin is allowed according to constraints
    */
    bool IsSpinAllowed( int axis );

    /** Claculate spin axis compared to original orientation
    */

    virtual void SpinAxisCalculate() {}

    void Print();

    virtual void encodeAsJSON(stringstream &jsonStr) = 0;
    virtual string getCSV() { return string(""); }

     double getWLocation()
    {
        return myWLocation;
    }
     void setWLocation( double w )
    {
        myWLocation = w;
    }
     double getHLocation()
    {
        return myHLocation;
    }
     void setHLocation( double h )
    {
        myHLocation = h;
    }
    double getLLocation()
    {
        return myLLocation;
    }
     void setLLocation( double h )
    {
        myLLocation = h;
    }

    void Weight( float w )
    {
        myWeight = w;
    }
    float Weight()
    {
        return myWeight;
    }

    void SpinAxis( int axis )
    {
        mySpinAxis = axis;
    }
    int SpinAxis()
    {
        return mySpinAxis;
    }
    bool getSpinLocation()  { return mySpinLocation; }
    void setSpinLocation( bool s ) { mySpinLocation = s; }
        string getSpin() { return ""; }
    virtual void AddToCutList( cCutList& l ) {}

    bool IsPacked()
    {
        return ( myBinProgID != -1 );
    }

static Item* Build(  item_build_instructions& instructions );

protected:
    int     myRotationConstraints;
    int     myPositionConstraints;
    double  myWLocation;
    double  myHLocation;
    double  myLLocation;
    bool    mySpinLocation;
    float   myWeight;

private:


    int     myBinProgID;
    int     mySpinAxis;         // zero means in original orientation
};

#endif	/* ITEM_H */

