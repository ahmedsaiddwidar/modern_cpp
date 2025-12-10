#include<iostream>
#include<algorithm>
#include<memory>


//Our modern application expects all shapes to have this specific drawing method
class Ishape{

    public:

    virtual ~Ishape() = default;

    virtual void draw(int x1, int y1, int x2, int y2) const = 0;
};

// This is a legacy class. We assume we CANNOT modify its code.
// It has a useful implementation, but a "wrong" interface.
class LegacyRectangle{

    public:
    
    void oldDraw(int x, int y, int height, int width) const{
        std::cout << "[Legacy API] Drawing rectangle starting at (" << x << "," << y
                  << ") with width " << width << " and height " << height << ".\n";
    }

};

// This is the bridge.
// 1. It inherits from the Target interface (IShape) so it looks like a modern shape.
// 2. It holds an instance of the Adaptee (LegacyRectangle) to do the actual work.
class RectangleAdapter  : public Ishape{

    private:

    std::unique_ptr<LegacyRectangle> m_legacyrect;

    public:
    //The adapter owns the legacy object
    RectangleAdapter(): m_legacyrect(std::make_unique<LegacyRectangle>()){}

    //The translation logic happens here
    void draw(int x1, int y1, int x2, int y2)const override{


        //Convert the input data from the modern format to the legacy format.
        // Calculate top-left corner (x, y)
        int x = std::min(x1, x2);
        int y = std::min(y1, y2);

        int width = std::abs(x1 - x2);
        int height = std::abs(y1 - y2);

        std::cout << "  -> Adapter converted to legacy format: x=" << x << ", y=" << y
                  << ", w=" << width << ", h=" << height << "\n";

        //Call the incompatible method on the legacy object.          
        m_legacyrect ->oldDraw(x, y, height, width);
    }

};

void renderShape(const Ishape& shape){

    std::cout << "Client: Requesting to draw a shape...\n";

    // The client passes coordinates in its preferred format.
    shape.draw(10,20,80,50);
}

int main() {
    std::cout << "--- Adapter Pattern Demo ---\n\n";

    // 1. Create the adapter.
    // From the outside, it just looks like an IShape.
    std::unique_ptr<Ishape> myRect = std::make_unique<RectangleAdapter>();

    // 2. Pass it to the client code.
    renderShape(*myRect);

    std::cout << "\n--- Demo Finished ---\n";
    // unique_ptr automatically cleans up the adapter, which cleans up the legacy rect.
    return 0;
}