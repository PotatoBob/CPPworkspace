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
    vec2 operator+(vec2 v2) {
        vec2 v1(x, y);
        v1.add(v2);
        return v1;
    }
    vec2 operator-(vec2 v2) {
        vec2 v1(x, y);
        v1.sub(v2);
        return v1;
    }
    vec2 operator*(vec2 v2) {
        vec2 v1(x, y);
        v1.mul(v2);
        return v1;
    }
    vec2 operator/(vec2 v2) {
        vec2 v1(x, y);
        v1.div(v2);
        return v1;
    }
    void operator+=(vec2 v2) {
        add(v2);
    }
    void operator-=(vec2 v2) {
        sub(v2);
    }
    void operator*=(vec2 v2) {
        mul(v2);
    }
    void operator/=(vec2 v2) {
        div(v2);
    }
    bool operator!=(vec2 v2) {
        return !equals(v2);
    }
    bool operator==(vec2 v2) {
        return equals(v2);
    }
};