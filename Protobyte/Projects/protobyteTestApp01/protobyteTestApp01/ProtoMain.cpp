#include "ProtoPlasm.h"
#include "ProtoController.h"
#include <iostream>

int main(int argc, char const** argv) {
		ijg::ProtoPlasm p(1200, 800, "ProtoController", new ProtoController());
		return EXIT_SUCCESS;
}