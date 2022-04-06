## start

    yarn
    yarn start

#

## react + typescript + jest

    yarn create react-app --template typescript

#

## redux-toolkit

    yarn add react-redux @reduxjs/toolkit
    yarn add -D @types/react-redux

#

## emotion

    yarn add @emotion/react @emotion/styled
    yarn add -D @emotion/babel-plugin

#

## storybook

    npx sb init

#

## babel

    yarn add -D @babel/core @babel/preset-env @babel/preset-react @babel/preset-typescript

#

## webpack

    yarn add -D webpack webpack-cli webpack-dev-server babel-loader style-loader css-loader file-loader ts-loader html-webpack-plugin

#

## electron

    yarn add electron-is-dev
    yarn add -D electron electron-builder concurrently cross-env wait-on

-   Electron-is-dev: 개발환경인지 빌드한 프로덕션환경인지 확인을 위하여 사용됨.
-   Electron : 일렉트론을 실행하기 위해서 사용됨.
-   Electron-builder : 일렉트론을 실제 프로덕션 버전으로 빌드하기 위해 사용됨.
-   concurrently : 동시에 여러 명령어를 사용(병렬적으로)하기 위해 사용됨.
-   cross-env : 프로그램을 CLI환경에서 실행 시킬 때에, OS에 관계 없이 환경변수를 설정할 수 있도록 하기 위해 사용됨.
-   wait-on : HTTP 자원, port, file등이 활성화 될 때 까지 기다려주는 cross platform

#

[babel, webpack] https://dev.to/deadwing7x/setup-a-react-app-using-webpack-babel-and-typescript-5927
[electron] https://velog.io/@dev_hikun/Electron-React-typescript-%EB%8D%B0%EC%8A%A4%ED%81%AC%ED%83%91-%EC%95%B1-%EB%A7%8C%EB%93%A4%EA%B8%B0-1-%EC%84%A4%EC%B9%98-%EB%B0%8F-%EC%84%A4%EC%A0%95
