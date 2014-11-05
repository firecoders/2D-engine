# 2D-engine

#### A C++ 2D game development library collection

2D-engine aims to provide a basic, reusable framework for building 2D games. It
is split up across multiple repositories, so you can pick and choose which parts
you want to use:

* [eventsystem][] `A generic C++ eventsystem library relying on templates`  
  eventsystem provides a central hub for event handling. It can also be used
  outside of games. ( for example in [s-torrent][] )

[eventsystem]: https://github.com/firecoders/eventsystem
[s-torrent]: https://github.com/froozen/s-torrent

* [2D-gui][] `A C++ gui library wrapping sfml and using our eventsystem project`  
  2D-gui serves as a connection between sfml and the eventsystem. It will also
  provide gui elements and can be used outside of games.

[2D-gui]: https://github.com/firecoders/2D-gui

* [gamelogic][] `A C++ library for 2D games`  

[gamelogic]: https://github.com/firecoders/gamelogic

* [boost.asio-wrapper][] `A C++ library, wrapping boost.asio, to be used for
  client or server applications`  

[boost.asio-wrapper]: https://github.com/firecoders/boost.asio-wrapper

## Projects using 2D-engine

* [packman][] `A packman implementation using the 2D-engine`  
  This is a reimplementation of shakmar's [cpp-games packman][cpp-games] onto
  the 2D-engine.

[packman]: https://github.com/firecoders/packman
[cpp-games]: https://github.com/shak-mar/cpp-games

## History

2D-engine started out as a library for creating RPGs, but throughout the
development process, we figured that we should go with a more general approach
instead.

Until we seperated eventsystem and 2D-gui, both were developed in this
repository. You can still browse [the old history][1].

[1]: https://github.com/firecoders/2D-engine/commits/v0.1.1
