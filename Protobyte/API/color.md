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
  - `ProtoColor3(T c);
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
    - `Col3`
  - `ProtoColor3<int>`
    - `ProtoColor3i`
    - `Col3i`
  - `ProtoColor3<double>
    - `ProtoColor3d`
    - `Col3d`
  - `ProtoColor3<long>`
    - `ProtoColor3L`
    - `Col3L`
  - `ProtoColor3<short>`
    - `ProtoColor3s`
    - `Col3s`
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
  - `ProtoColor4<int>`
    - `ProtoColor4i`
    - `Col4i`
  - `ProtoColor4<double>`
    - `ProtoColor4d`
    - `Col4d`
  - `ProtoColor4<long>`
    - `ProtoColor4L`
    - `Col4L`
  - `ProtoColor4<short>`
    - `ProtoColor4s`
    - `Col4s`
  - `ProtoColor<unsigned char>`
    - `ProtoColor4b`
    - `Col4b`

### Notes
