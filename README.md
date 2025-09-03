# callaudiod - Call audio routing daemon
`callaudiod` is a daemon for dealing with audio routing during phone calls.

It provides a D-Bus interface allowing other programs to:
  * switch audio profiles
  * output audio to the speaker or back to its original port
  * mute the microphone

## Deprecation notice

`callaudiod` and all its functionality is currently deprecated. Support for
switching audio profiles during phone calls is now upstream in WirePlumber. For
other functionality:

* Use the simple pulseaudio API (`pa_context_set_source_mute_by_*`) for muting
  devices.
* Add support for changing to speaker in your applications. There might be
  support for it in the future in
  [pipewire](https://gitlab.freedesktop.org/pipewire/pipewire/-/issues/4868),
  but that is not warrantied.

## Dependencies

`callaudiod` requires the following development libraries:
- libasound2-dev
- libglib2.0-dev
- libpulse-dev

## Building

`callaudiod` uses meson as its build system. Building and installing
`callaudiod` is as simple as running the following commands:

```
$ meson ../callaudiod-build
$ ninja -C ../callaudiod-build
# ninja -C ../callaudiod-build install
```

## Running

`callaudiod` is usually run as a systemd user service, but can also be manually
started from the command-line:

```
$ callaudiod
```

## License

`callaudiod` is licensed under the GPLv3+.
