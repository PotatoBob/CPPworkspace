struct vec2 {
    float x;
    float y;
    void add(vec2 v) {
        this -> x += v.x;
        this -> y += v.y;
    }
    void sub(vec2 v) {
        this -> x -= v.x;
        this -> y -= v.y;
    }
    void mul (vec2 v) {
        this -> x *= v.x;
        this -> y *= v.y;
    }
    void div (vec2 v) {
        this -> x /= v.x;
        this -> y /= v.y;
    }
    bool equals (vec2 v) {
        if(this -> x == v.x) {
            return true;
        } 
        else {
            return false;
        }
        
    }
    vec2() {};
    vec2(float v) {
        this -> x = v;
        this -> y = v;
    }
    vec2(float x, float y) {
        this -> x = x;
        this -> y = y;
    }
};