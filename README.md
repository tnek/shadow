# Shadow

A jailbreak detection bypass for modern iOS jailbreaks.

## Frequently Asked Questions

> Can you add support/bypass for *app name*?

No. Technically, I don't "add support" for apps. Nothing in Shadow is designed specifically for any app.

> *app name* keeps crashing with Shadow enabled.

Please create a new Issue with details about your Shadow settings if this is not detection related.

> *app name* runs slow with Shadow enabled.

This is expected behaviour due to extra processing by Shadow.

> Apps trigger detection when a certain tweak is installed.

Please create a new Issue with the name of the tweak and I can try to investigate further.

> *Questions related to Xina*

As of now I will choose not to offer support for running Shadow on Xina jailbroken devices. Without being able to test Shadow in a full capacity, I cannot guarantee the same results when attempting to bypass detection.

## Troubleshooting

If your jailbreak is still getting detected, here are some things to try:

* Disable any compatibility settings.
* Try a different hooking library. `fishhook` usually gets good results and is highly compatible, but may not work for all apps.
* Disable all tweaks except Shadow. You can use Choicy or libhooker Configurator to do this.
* Use vnodebypass, if supported on your system.
* If semi-(un)tethered, reboot into normal jailed iOS and use the app. This is inconvenient but it can work if app developers are implementing detection "the proper way".
* Use another bypass tweak, ideally an app-specific bypass tweak. Be wary of enabling multiple bypass tweaks in case of conflicts.
* Downgrade the app. Sometimes, newer versions have updated detection methods.

## Contributing

Pull requests are welcome. For translations, please refer to the [English translation](preferencebundle/Resources/en.lproj/) within the preference bundle resource files.

## Installation

Add my [repo](https://ios.jjolano.me) to your package manager and install the Shadow (`me.jjolano.shadow`) package. Alternatively, download the [latest release](https://github.com/jjolano/shadow/releases/latest) directly from GitHub and open the file with your package manager.

You may need additional repositories for dependencies - these are the current dependencies:

* `libSandy` from [opa334's Repo](https://opa334.github.io)
* `AltList` from [opa334‘s Repo](https://opa334.github.io)
* `HookKit Framework`

## Usage

After installation, settings are available in the Settings app. You may configure global defaults, or add an app-specific configuration. Shadow allows fine-grained control of its bypass strength, so there will be many options available to configure.

## Legal

*Copyright Act*, RSC 1985, c C-42, s 41.12.
