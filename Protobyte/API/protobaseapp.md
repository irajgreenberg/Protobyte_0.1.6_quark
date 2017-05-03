# ProtoBaseApp

## ProtoBaseApp (Class)

### Private Members
  - `Col3f bgColor;`

### Public Members
  - `Col4f fillColor;`
  - `Col4f strokeColor;`

### Public Member Functions

#### Color
  - `Col3f toCol3f(const Col4f& col);`
  - `Col4f toCol4f(const Col3f& col);`

#### Background
  - `void setBackground(float r, float g, float b);`
  - `void setBackground(float c);`
  - `void setBackground(const Col3f& col);`

#### Fill
  - `void fill(const Col4f& col);`
  - `void fill(float gray);`
  - `void fill(float gray, float a);`
  - `void fill(float r, float g, float b)`;
  - `void fill(float r, float g, float b, float a)`
  - `void noFill()`

#### Stroke
  - `void stroke(const Col4f& col);`
  - `void stroke(float gray);`
  - `void stroke(float gray, float a);`
  - `void stroke(float r, float g, float b);`
  - `void stroke(float r, float g, float b, float a);`
  - `void noStroke();`
  - `void strokeWeight(float lineWidth = 1.0);`

#### Lighting and Materials
  - `void setSpecular(const Col4f& spec);`
  - `void setShininess(float shininess);`
  - `void setDiffuseMaterial(const Col4f& diff);`
  - `void setAmbientMaterial(const Col4f& amb);`

#### Unknown
  - `std::vector<std::tuple<Vec3f, char, Col4f, Col4f, float>> pathVerticesAll;`