# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

import os
import sys

project = "Ananke"
copyright = "2026 Filippo Savi"
author = "Filippo Savi"

# -- General configuration ---------------------------------------------------

extensions = [
    "sphinx.ext.autodoc",
    "sphinx.ext.intersphinx",
    "sphinx.ext.todo",
    "sphinx.ext.viewcode",
]

templates_path = ["_templates"]
exclude_patterns = ["_build", "Thumbs.db", ".DS_Store"]

# Options for HTML output -----------------------------------------------------

html_theme = "alabaster"
html_static_path = ["_static"]

# Options for sphinx.ext.todo ------------------------------------------------

todo_include_todos = True

# -- Options for intersphinx ------------------------------------------------

intersphinx_mapping = {
    "python": ("https://docs.python.org/3", None),
}
