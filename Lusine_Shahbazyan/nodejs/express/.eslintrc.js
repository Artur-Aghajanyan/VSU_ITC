module.exports = {
    "env": {
        "browser": true,
        "commonjs": true,
        "es2021": true
    },
    "extends": [
        "eslint:recommended",
        "plugin:node/recommended"
    ],
    "parserOptions": {
        "ecmaVersion": 12
    },
    "ignorePatterns": ["**.test.js", "node_modules"],
    "rules": {
        "no-multi-spaces": [2, { exceptions: { "VariableDeclaration": true} }],
        "indent": [2, 4],
        "linebreak-style": 2,
        "semi": 2,
        "comma-dangle": [2, {
            "arrays": "never",
            "objects": "never",
            "imports": "never",
            "functions": "never"
        }],
        "no-unused-expressions": 2,
        "no-console": 1,
        "no-alert": 2,
        "no-undef": 2,
        "no-unused-vars": [2, { "args": "none" }],
        "node/no-extraneous-require": ["error", {
            "tryExtensions": []
        }]
    }
};
