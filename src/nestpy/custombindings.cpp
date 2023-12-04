#include <pybind11/pybind11.h>
#include "NEST.hh"
#include "LArNEST.hh"
#include "VDetector.hh"
#include "execNEST.hh"
#include "TestSpectra.hh"
#include "LUX_Run03.hh"
#include "DetectorExample_XENON10.hh"
#include "RandomGen.hh"
#include <pybind11/numpy.h>
#include <pybind11/stl_bind.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

PYBIND11_MODULE(nestpy, m)
{
// versioning
#ifdef NESTPY_VERSION
    m.attr("__version__") = MACRO_STRINGIFY(NESTPY_VERSION);
#else
m.attr("__version__") = "dev";
#endif
#ifdef NEST_VERSION
    m.attr("__nest_version__") = MACRO_STRINGIFY(NEST_VERSION);
#else
    m.attr("__nest_version__") = "";
#endif
    //	Binding for the NESTcalc class only custom added function
    py::class_<NEST::NESTcalc, std::unique_ptr<NEST::NESTcalc, py::nodelete>>(m, "NESTcalc")
        .def(py::init<>())
        .def_static("GetDiffTran_Liquid", &NEST::NESTcalc::GetDiffTran_Liquid,
            py::arg("dfield") = 200.,
            py::arg("highFieldModel") = false,
            py::arg("T") = 177.15,
            py::arg("Z") = 54
        )
        .def_static("GetDiffLong_Liquid", &NEST::NESTcalc::GetDiffLong_Liquid,
            py::arg("dfield") = 200.,
            py::arg("highFieldModel") = false,
            py::arg("T") = 177.15,
            py::arg("Z") = 54
        )
}
