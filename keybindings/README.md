# Libreoffice keybindings template

A libreoffice extension is essentially a zip file which contains some
configuration files, some program/logic files, and some files like
license, description etc.

This repository is an unzipped extension intended to be used as a template
for customizing keybindings (keyboard shortcuts) in libreoffice.

Setting custom keyboard shortcuts in libreoffice is possible via
`tools > customize > keyboard`, but that becomes tedious rather quickly
if the number of shortcuts to set is large. Instead the community can
use this template to create extensions for using keyboard shortcuts
from other applications.

For example: John likes MSO keyboard shortcuts, so he can download this
repository, then in the `Keybindings.xcu` file, he can change "which key
combination maps to which command" and then zip this into an extension
using the command below. Do remember to change the developer and copyright
information.

```bash
cd ExtensionRepository
zip -r ExtensionName.oxt "."

# or

zip -r ExtensionName.oxt ExtensionRepositoryPath
```

Another approach can be to download an extension (made out of this template)
from the extensions repository, and rename that to `ExtensionName.zip`. Then one
can very easily unzip `ExtensionName.zip` and customize it to their liking.
