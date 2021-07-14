module.exports = {
    env: {
        node: true,
        commonjs: true,
        es2021: true,
    },
    extends: [
        'eslint:recommended',
        'plugin:node/recommended',
    ],
    parserOptions: {
        ecmaVersion: 12,
    },
    rules: {
        'no-console': 2,
        'node/exports-style': 'error',
        'node/file-extension-in-import': 2,
        'node/prefer-global/buffer': 'error',
        'node/prefer-global/console': 2,
        'node/prefer-global/process': 'error',
        'node/prefer-global/url-search-params': 2,
        'node/prefer-global/url': 'error',
        'node/prefer-promises/dns': 2,
        'node/prefer-promises/fs': 'error',
    },
};
