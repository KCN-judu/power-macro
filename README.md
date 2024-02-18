Power Macro
==========
## Dev Notice

### Due to the aim of  Multi-Platform Support
We decided to use Node.js C++ addons as under-layer implementations.

### Due to develop Node.js C++ addons in this proj will lead to bloating and complexity increasing
We decided to create new repos to store these Node.js C++ addons proj.  
[pm-win-api](https://github.com/KCN-judu/pm-win-api) repo: under-layer implementation on Windows


## Introduce

### What is Power Macro?

Power Macro allows for the recording and playback of keyboard and mouse actions, providing the ability to automate repetitive tasks and enhance productivity.  
Custom hotkey macro feature will added in the future version. You can also write a macro file in given format.

### Power Macro is supported on which platform?

Currently, Power Macro is **ONLY SUPPORTED** on the Windows platform. We plan to introduce support for the Linux Platform in future versions.

## Usage
### How to manually write a macro file?

In the macro file, make sure each line contains **ONLY ONE COMMAND** and there is **NO EMPTY LINE**.

#### Basic command structure is:  
``` InteractionType [arg1] [arg2] ...```

| Interaction Type | Device | Meaning | Args |
| :--------------: | :----: | :-----: | :-----: |
| L_DOWN | mouse | press left key| none |
| L_UP | mouse | release left key| none |
| R_DOWN | mouse | press right key| none |
| R_UP | mouse | release right key| none |
| MID_DOWN | mouse | press middle key| none |
| MID_UP | mouse | release middle key| none |
| L_CLICK | mouse | left click | none |
| R_CLICK | mouse | right click | none |
| DBL_CLICK | mouse | double click | none |
| MID_CLICK | mouse | middle click | none |
| MOVE | mouse | move to ```(x,y)``` with step length | ```<MV_TYPE>, <x>, <y>, [step]``` |
| DRAG | mouse | drag to ```(x,y)``` with step length | ```<MV_TYPE>, <x>, <y>, [step]``` |
| PRESS | keyboard | press key| ```<key>``` |
| RELEASE | keyboard | release key| ```<key>``` |

#### Special arg type:  

1. ```MV_TYPE``` is a 8-bit number, you can set different move or drag mode by this. You can create a composed mode by ```|``` operation. Such as smooth move in absolute position is ```MV_SMOOTH | MV_ABSOLUTE```

   | Name        | Value |
   | :---------: | :---: |
   | MV_STRAIGHT | 0x01  |
   | MV_SMOOTH   | 0x02  |
   | MV_ABSOLUTE | 0x04  |


  
  



