# Color

## ProtoColor3 (Template)

red, green, blue

### Public Members
  - `T r;`
    - red color component
  - `T g;`
    - green color component
  - `T b;`
    - blue color component

### Constructors
  - `ProtoColor3();`
  - `ProtoColor3(T r, T g, T b);`

### Getters
  - `T getR() const;`
  - `T getG() const;`
  - `T getB() const;`

### Setters
  - `void setR(T r);`
  - `void setG(T g);`
  - `void setB(T b);`

### Overloaded Operators
  - `<<`

### Aliases
  - `ProtoColor3<float>`
    - `ProtoColor3f`
    - `Col3f`
  - `ProtoColor3<int>`
    - `ProtoColor3i`
    - `Col3i`
  - `ProtoColor3<unsigned char>`
    - `ProtoColor3b`
    - `Col3b`

### Notes

## ProtoColor4 (Template)

red, green, blue, alpha

### Public Members
  - `T r;`
    - red color component
  - `T g;`
    - green color component
  - `T b;`
    - blue color component
  - `T a;`
    - alpha color component

### Constructors
  - `ProtoColor4();`
  - `ProtoColor4(T c);`
  - `ProtoColor4(T c, T a);`
  - `ProtoColor4(T r, T g, T b);`
  - `ProtoColor4(T r, T g, T b, T a);`

### Getters
  - `T getR() const;`
  - `T getG() const;`
  - `T getB() const;`
  - `T getA() const;

### Setters
  - `void setR(T r);`
  - `void setG(T g);`
  - `void setB(T b);`
  - `void setA(T a);`

### Overloaded Operators
  - `<<`

### Aliases
  - `ProtoColor4<float>`
    - `ProtoColor4f`
    - `Col4f`
    - `Col4`
  - `ProtoColor4<double>`
    - `Col4d`
  - `ProtoColor4<int>
    - `ProtoColor4i`
    - `Col4i`
  - `ProtoColor4<long>`
    - `Col4L`
  - `ProtoColor4<short>`
    - `Col4s`
  - `ProtoColor<unsigned char>`
    - `ProtoColor4b`
    - `Col4b`

### Notes
