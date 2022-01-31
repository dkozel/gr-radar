/*
 * Copyright 2022 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(find_max_peak_c.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(24fbff5018a01a6f4563a40d9a3f89cb)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <radar/find_max_peak_c.h>
// pydoc.h is automatically generated in the build directory
#include <find_max_peak_c_pydoc.h>

void bind_find_max_peak_c(py::module& m)
{

    using find_max_peak_c = ::gr::radar::find_max_peak_c;


    py::class_<find_max_peak_c,
               gr::tagged_stream_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<find_max_peak_c>>(m, "find_max_peak_c", D(find_max_peak_c))

        .def(py::init(&find_max_peak_c::make),
             py::arg("samp_rate"),
             py::arg("threshold"),
             py::arg("samp_protect"),
             py::arg("max_freq"),
             py::arg("cut_max_freq"),
             py::arg("len_key") = "packet_len",
             D(find_max_peak_c, make))


        .def("set_threshold",
             &find_max_peak_c::set_threshold,
             py::arg("threshold"),
             D(find_max_peak_c, set_threshold))


        .def("set_samp_protect",
             &find_max_peak_c::set_samp_protect,
             py::arg("samp"),
             D(find_max_peak_c, set_samp_protect))


        .def("set_max_freq",
             &find_max_peak_c::set_max_freq,
             py::arg("freq"),
             D(find_max_peak_c, set_max_freq))

        ;
}