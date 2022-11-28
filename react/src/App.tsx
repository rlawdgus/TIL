import React, { useEffect, useState } from "react";

import VirtualizedList from "./containers/virtualized/VirtualizedList";
import VirtualizingItem from "./components/virtualized/VirtualizingItem";

export type Post = {
  id: number;
  userId: number;
  title: string;
  body: string;
};

function App() {
  const [posts, setPosts] = useState<Post[]>([]);

  useEffect(() => {
    fetch("https://jsonplaceholder.typicode.com/posts").then((response) => {
      const data = response.json();

      data.then((posts) => {
        setPosts(posts);
      });
    });
  }, []);

  return <VirtualizedList posts={posts} Item={VirtualizingItem} />;
}

export default App;

// https://velog.io/@kimjh96/react-virtualized-%EB%A0%8C%EB%8D%94%EB%A7%81-%EC%84%B1%EB%8A%A5-%EC%B5%9C%EC%A0%81%ED%99%94
