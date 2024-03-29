# moveOS

***moveOS*** consists of a *lightweight Kernel* and supporting libraries that greatly help in developing and deploying *movable* and *immovable* ***smart***-objects spanning a variety of domains. The main, desirable features:

&nbsp; &nbsp; <sup>:star:</sup> &nbsp; *Ease of use*

&nbsp; &nbsp; <sup>:star:</sup> &nbsp; *Lightweight deployments*

&nbsp; &nbsp; <sup>:star:</sup> &nbsp; *Energy efficiency*

&nbsp; &nbsp; <sup>:star:</sup> &nbsp; *Real-time responsiveness*

&nbsp; &nbsp; <sup>:star:</sup> &nbsp; *Encouraging the task and event-based designs*

&nbsp; &nbsp; <sup>:star:</sup> &nbsp; *Natively supporting the State Machines*

&nbsp; &nbsp; <sup>:star:</sup> &nbsp; *Graphical and headless deployments*

&nbsp; &nbsp; <sup>:star:</sup> &nbsp; *Remote interfacing through stand-alone graphical and cloud-based services*

&nbsp; &nbsp; <sup>:star:</sup> &nbsp; *Ready-to-use security and extensible modules*

&nbsp; &nbsp; <sup>:star:</sup> &nbsp; *Low-code and no-code facilities*

&nbsp; &nbsp; <sup>:star:</sup> &nbsp; *ROS integration*

&nbsp; &nbsp; <sup>:star:</sup> &nbsp; *High configurability, extensibility and agility*



&nbsp;

## Run-time Environment

From the beginning, the ***moveOS*** is intended to be deployed on bare-metal devices, Windows and Linux distributions; though, its behavior can change depending on deployed environments and underlying hardware features. The requisite workflow is envisioned as:

```mermaid
graph TD;
  A(Design / Logic Implementation) --> B(Hosted Execution at Windows / Linux Distribution)
  B --> A
  A -.-> C{Stable Design?}
  C -.-> |Yes|D(Deployment to Device)
  C -.-> |No|A
```



&nbsp;

## Modules

***moveOS*** comprises of two types of modules i.e., Compiled with the Kernel itself, and the ones loaded as pure modules that can be unloaded at any time - just like the Linux Kernel modules.



&nbsp;

## Documentation

Documentation is kept in docs folder.


&nbsp;

For using the OS and libraries:

  * Defining [tasks](./docs/usage/Tasks.md)
  * Defining [State Machines](./docs/usage/StateMachine.md)


&nbsp;

How it is arranged?

  * [Architectural Overview](./docs/contrib/Architecture.md)
  * Conditional Compilation [Definitions](./docs/contrib/Defines.md)
