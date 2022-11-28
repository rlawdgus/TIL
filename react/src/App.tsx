import React, { useEffect, useState } from "react";
import {
  WindowScroller,
  CellMeasurer,
  CellMeasurerCache,
  AutoSizer,
  List,
  ListRowProps,
} from "react-virtualized";

type Post = {
  id: number;
  userId: number;
  title: string;
  body: string;
};

const cache = new CellMeasurerCache({
  defaultWidth: 100,
  fixedWidth: true,
});

function App() {
  const [posts, setPosts] = useState<Post[]>([]);

  const rowRenderer = ({ index, key, parent, style }: ListRowProps) => {
    return (
      <CellMeasurer
        cache={cache}
        parent={parent}
        key={key}
        columnIndex={0}
        rowIndex={index}
      >
        <div style={style}>
          <div
            style={{
              padding: 8,
              marginBottom: 8,
              color: "white",
              backgroundColor: "#282c34",
            }}
          >
            <div>index: {index}</div>
            <div>id: {posts[index].id}</div>
            <div>userId: {posts[index].userId}</div>
            <div>title: {posts[index].title}</div>
            <div>body: {posts[index].body}</div>
          </div>
        </div>
      </CellMeasurer>
    );
  };

  useEffect(() => {
    fetch("https://jsonplaceholder.typicode.com/posts").then((response) => {
      const data = response.json();

      data.then((posts) => {
        setPosts(posts);
      });
    });
  }, []);

  return (
    <WindowScroller>
      {({ height, scrollTop, isScrolling, onChildScroll }) => (
        <AutoSizer disableHeight>
          {({ width }) => (
            <List
              autoHeight
              height={height}
              width={width}
              isScrolling={isScrolling}
              overscanRowCount={0}
              onScroll={onChildScroll}
              scrollTop={scrollTop}
              rowCount={posts.length}
              rowHeight={cache.rowHeight}
              rowRenderer={rowRenderer}
              deferredMeasurementCache={cache}
            />
          )}
        </AutoSizer>
      )}
    </WindowScroller>
  );
}

export default App;

// https://velog.io/@kimjh96/react-virtualized-%EB%A0%8C%EB%8D%94%EB%A7%81-%EC%84%B1%EB%8A%A5-%EC%B5%9C%EC%A0%81%ED%99%94
