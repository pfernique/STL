#include "_stl.h"


void wrapper_0fd38e01161354208eee1b15bf0b7128()
{

    std::string name_fa414b05d29e5f4ea0b6d6cb5cf81b01 = boost::python::extract< std::string >(boost::python::scope().attr("__name__") + ".statiskit");
    boost::python::object module_fa414b05d29e5f4ea0b6d6cb5cf81b01(boost::python::handle<  >(boost::python::borrowed(PyImport_AddModule(name_fa414b05d29e5f4ea0b6d6cb5cf81b01.c_str()))));
    boost::python::scope().attr("statiskit") = module_fa414b05d29e5f4ea0b6d6cb5cf81b01;
    boost::python::scope scope_fa414b05d29e5f4ea0b6d6cb5cf81b01 = module_fa414b05d29e5f4ea0b6d6cb5cf81b01;
    std::string name_f1ab29faa1815285a06ca52391d1425f = boost::python::extract< std::string >(boost::python::scope().attr("__name__") + ".stl");
    boost::python::object module_f1ab29faa1815285a06ca52391d1425f(boost::python::handle<  >(boost::python::borrowed(PyImport_AddModule(name_f1ab29faa1815285a06ca52391d1425f.c_str()))));
    boost::python::scope().attr("stl") = module_f1ab29faa1815285a06ca52391d1425f;
    boost::python::scope scope_f1ab29faa1815285a06ca52391d1425f = module_f1ab29faa1815285a06ca52391d1425f;
    ::statiskit::stl::SetIndexGenerator  (*function_pointer_0fd38e01161354208eee1b15bf0b7128)(int const &) = ::statiskit::stl::generator;
    boost::python::def("__iter__", function_pointer_0fd38e01161354208eee1b15bf0b7128, "");
}