# 1NT18IS076_kaushal_B_NPLab

A documentation repo for recording day to day progress of NP Lab 6th sem.

# Note:
This repo is no longer maintained. I have another GitHub account for college stuff which is forked from this repo. You can visit that [here](https://github.com/1NT18IS076/1NT18IS076_kaushal_B_npLab).

# To install:

Visit [here](https://www.nsnam.org/releases/ns-3-30/download/) to download the source code. Unzip the tar file and continnue with the procedure below.

### Note:
For the above step, you'll need to compile both ns3 and netanim yourself. If you want the prebuilt binaries, you can visit [this](https://drive.google.com/file/d/1GZysjMt88bO_2EeYX6D_epMgTr5053QL/view?usp=sharing) link, where I have compiled everything needed. You can then continue with the procedure of execution as expected.

# To run:

```bash
sudo su
cd ns-all [TAB]
cd ns [TAB]
cd scratch [TAB]

[Write your program]

cd ..
[If you are running it for the first time (without compiling), configure waf by running => $ ./waf configure]
./waf
./waf --run scratch/filename [without extension]
cd ..
export QT_X11_NO_MITSHM=1
cd netanim-3.108 [TAB] # see to it that you visit the right folder
./Netanim [TAB]

# now open the xml file saved in the GUI, and click on the run button
# configure the options, like keep the speed as 'slow', to observe the packet
```

This is how you run a program in Part B in this repository on the lab computers.
