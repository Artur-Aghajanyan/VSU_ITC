module.exports = {
    "env": {
        "browser": true,
        "es2021": true
    },
	"extends": [
        "eslint:recommended",
        "plugin:node/recommended",
		"plugin:vue/strongly-recommended"
    ],
    //"ignoreProperties": false,
	//"ignoreEOLComments": true,
    "parserOptions": {
        "ecmaVersion": 12
    },
    "rules": {
		 "node/exports-style": ["error", "module.exports"],
        "node/file-extension-in-import": ["error", "always"],
        "node/prefer-global/buffer": ["error", "always"],
        "node/prefer-global/console": ["error", "always"],
        "node/prefer-global/process": ["error", "always"],
        "node/prefer-global/url-search-params": ["error", "always"],
        "node/prefer-global/url": ["error", "always"],
        "node/prefer-promises/dns": "error",
        //"node/prefer-promises/fs": "error",
		"no-multi-spaces": ["error"],
		"keyword-spacing": ["error", {"after": false}],
		"space-infix-ops": ["error"],
		//"no-tabs": ["error"] 
		"indent": "error",
		"no-multiple-empty-lines": "error",
		"semi": ["error", "always"],
		"comma-dangle": ["error", "never"],
    // or
    "comma-dangle": ["error", {
        "arrays": "never",
        "objects": "never",
        "imports": "never",
        "exports": "never",
        "functions": "never"
    }],
	"no-unused-vars": "error",
	"no-console": ["error", { allow: ["warn", "error"] }],
	"no-alert": "error",
	"no-undef": "error"
    }
};


