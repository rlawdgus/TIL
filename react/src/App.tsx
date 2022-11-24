import List from "./containers/virtualized/List";

const LIST = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15];

const App = () => {
  return <List list={LIST} windowHeight={300} itemHeight={50} />;
};

export default App;
