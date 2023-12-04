# nestpy

[![Join the chat at https://gitter.im/NESTCollaboration/nestpy](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/NESTCollaboration/nestpy?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)
[![Pytest](https://github.com/NESTCollaboration/nestpy/actions/workflows/test_package.yml/badge.svg?branch=master)](https://github.com/NESTCollaboration/nestpy/actions/workflows/test_package.yml)
[![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.1345595.svg)](https://doi.org/10.5281/zenodo.1345595)
[![PyPi version](https://pypip.in/v/nestpy/badge.png)](https://pypi.org/project/nestpy/)
[![Project Status: Active – The project has reached a stable, usable state and is being actively developed.](https://www.repostatus.org/badges/latest/active.svg)](https://www.repostatus.org/#active)
[![Python Versions](https://img.shields.io/pypi/pyversions/nestpy.svg)](https://pypi.python.org/pypi/nestpy)
[![PyPI downloads](https://img.shields.io/pypi/dm/nestpy.svg)](https://pypistats.org/packages/nestpy)

Visit the tutorials directory for tutorials on the nestpy calls, maintenance, and benchmark plots. 

These are the Python bindings for the [NEST library](https://github.com/NESTCollaboration/nest), which provides a direct wrapping of functionality. Forked to add some required function for DARWIN. The library is now pythonic, so be weary of the separate naming conventions for functions/variables from the C++ library.

You do *not* have to have NEST already installed to use this package.

## Installing from PyPI

For 64-bit Linux or Mac systems, instally 'nestpy' should just require running:

```
pip install nestpy
```

You can then test that it works by running the example above.

## Installing from source

Requirements: You must have CMake>=3.6 and a C++17 compatible compiler (GCC>=4.8) to build.

First, you must check out this repository then simply run the installer:

```
git clone https://github.com/yukai-zh/nestpy.git
cd nestpy
git submodule update --init --recursive
pip install .
```

## Installing with custom NEST code

Almost all NEST users will want to incorporate some custom code into their workflow, such as custom Detector files or TestSpectra.  In order to incorporate that custom code into the nestpy installation, you'll have to copy the files you've edited into the lib/nest/ directory and rerun:
```
pip install .
```

In order to create a more efficient workflow, we suggest the user takes the following steps:

  1. Fork the official NEST repository into your own public/private one.
  2. Make whatever changes to your fork and maintain them with commits.
  3. Download or fork nestpy and change the NEST entry in the .gitmodules files to point to your custom fork of NEST.

```
[submodule "lib/nest"]
	path = lib/nest
	url = https://github.com/NESTCollaboration/nest # change this to any custom fork of NEST if you want to use your own code!
[submodule "lib/gcem"]
	path = lib/gcem
	url = https://github.com/kthohr/gcem.git
[submodule "lib/pybind11"]
	path = lib/pybind11
	url = https://github.com/pybind/pybind11.git
```

## Usage

Python bindings to the NEST library:

```
import nestpy

# This is same as C++ NEST with naming
nc = nestpy.NESTcalc(nestpy.VDetector())

interaction = nestpy.INTERACTION_TYPE(0)  # NR

E = 10  # keV
print('For an %s keV %s' % (E, interaction))

# Get particle yields
y = nc.GetYields(interaction,
		 E)

print('The photon yield is:', y.PhotonYield)
print('With statistical fluctuations',
      nc.GetQuanta(y).photons)
```

For more examples on possible calls, please see the tests and tutorials folders.

### Support

* Bugs: Please report bugs to the [issue tracker on Github](https://github.com/NESTCollaboration/nestpy/issues) such that we can keep track of them and eventually fix them.  Please explain how to reproduce the issue (including code) and which system you are running on.
* Help: Help can be provided also via the issue tracker by tagging your issue with 'question'
* Contributing:  Please fork this repository then make a pull request.  In this pull request, explain the details of your change and include tests.

## Technical implementation

This package is a [pybind11](https://pybind11.readthedocs.io/en/stable/intro.html) wrapper of [NEST](https://github.com/NESTCollaboration/nest) that uses [GitHub Workflows](https://docs.github.com/en/actions/using-workflows) to build binaries using the [manylinux](https://github.com/pypa/python-manylinux-demo) [Docker image](https://www.docker.com) from [this page](https://github.com/RalfG/python-wheels-manylinux-build).

* Help from Henry Schreiner, which included a great [binding tutorial](https://indico.cern.ch/event/694818/contributions/2985778/attachments/1682465/2703470/PyHEPTalk.pdf)
* Implementation also based on [this](http://www.benjack.io/2018/02/02/python-cpp-revisited.html)
* Implementation of GitHub test and build actions was made possible by [Joran Angevaare](https://github.com/joranangevaare).

See AUTHORS.md for information on the developers.

## Citation

When you use `nestpy`, please say so in your slides or publications (for publications, see Zenodo link above).  You can mention this in addition to how you cite NEST.  This is important for us being able to get funding to support this project.
