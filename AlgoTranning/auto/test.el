(TeX-add-style-hook
 "test"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("inputenc" "utf8") ("babel" "english")))
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art10"
    "inputenc"
    "babel"
    "mathtools"
    "minted"))
 :latex)

