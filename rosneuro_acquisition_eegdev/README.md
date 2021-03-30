# ROSNeuro Acquisition EEGDEV Plugin

The **EEGDEv** plugin allows to acquire neurodata from different commercial amplifiers. The plugin strongly relies on [libeegdev](https://neuro.debian.net/pkgs/libeegdev-dev.html) and [libxdffileio](https://neuro.debian.net/pkgs/libxdffileio-dev.html), two open source libraries available in neurodebian repository.

## Usage
Instructions on how to install xdffileio and eegdev are provided below. Here, we will have a look the usage of the **EEGDEV Plugin**.

To launch the rosneuro_acquisition with the EEGDEV plugin, first it is required to set the `plugin` parameter to `rosneuro::EGDDevice`, then to provide the desired `framerate`. Notice that these are the two mandatory parameters for every plugin of rosneuro_acquisition.

### Plugin-specific parameters:
~<name>/`devarg` (`std::string`) [**mandatory**]
	
  The device name according to eegdev library.

~<name>/`samplerate` (`int`)
  
  Samplerate (in Hz) to be set in the device (if allowed by the hardware). If it is not provided, the default sampling rate of the device will be used.
  
~<name>/`devext` (`std::string`)
  
  Additional extra arguments for the specific device. Please refer to libeegdev for more details.

#### Possible devarg identifiers:
  | devarg | Device |
  |:------:|:------:|
  | \*.gdf | Fullpath of GDF file for playback |
  | \*.bdf | Fullpath of BDF file for playback |
  | gtec | g.USBamp from g.Tec |
  | eego | AntNeuro eego device |
  | biosemi | Biosemi device |
  | q20 | Cognionics Quick-20 device |
  | wsdsi | Wearable sensing device |
  | gtecnet | g.TecNet language support |
  | bbt | Bit Brain device |
  | neurone | Neurone device |
  | barv | BrainProduct RDA support |
  | tia | Tobi interface A support |
  | neurosky | Neurosky device |



## Installing *eegdev* and *xdffileio*
The plugin requires the installation of **libeegdev** and **libxdffileio**. The libraries can be installed from packages of from source.

### Package installation
The debian packges are available here:
- [libxdffileio](https://neuro.debian.net/pkgs/libxdffileio.html)
- [libxdffileio-dev](https://neuro.debian.net/pkgs/libxdffileio-dev.html)
- [libeegdev](https://neuro.debian.net/pkgs/libeegdev.html)
- [libeegdev-dev](https://neuro.debian.net/pkgs/libeegdev-dev.html)

Download the packages and run the command:

```bash
sudo dpkg -i libxdffile* libeegdev*
```
### Source compilation and installation
A more updated version of the libraries is available here:
- [rosneuro/xdffileio](https://bitbucket.org/rosneuro/xdffileio)
- [rosneuro/eegdev](https://bitbucket.org/rosneuro/eegdev)

To compile the libraries you need to install the following packages: `sudo apt-get install libtool gnulib flex bison`.
Furthermore, **libeegdev** provides support for a variety of devices and some of them has proprietary drivers. The drivers must be installed on the system to enable the support for the specific device.

#### xdffileio
First, clone the xdffileio repository:
```bash
git clone https://ltonin@bitbucket.org/rosneuro/xdffileio.git
```
Enter in the `xdffileio` directory and run:
```bash
./autogen.sh
```
This script setup the folder with libtool and gnulib.

At this point, run the configure:
```bash
./configure
```
Compile and install the library
```bash
make && sudo make install
```
#### eegdev
As before, first clone the eegdev repository:
```bash
git clone https://ltonin@bitbucket.org/rosneuro/eegdev.git
```
Enter in the `eegdev` directory and run:
```bash
./autogen.sh
```
This script setup the folder with libtool and gnulib.

At this point, run the configure:
```bash
./configure
```
**At the end of the configure, a table will show the supported devices (according to the driver installed in your machine).**
Compile and install the library:
```bash
make && sudo make install
```


