import { type Post } from "../../App";

export interface ItemProps extends Post {
  index: number;
}

const VirtualizingItem = ({index, id, userId, title, body}: ItemProps) => {
  return (
    <div
      style={{
        padding: 8,
        marginBottom: 8,
        color: "white",
        backgroundColor: "#282c34",
      }}
    >
      <div>index: {index}</div>
      <div>id: {id}</div>
      <div>userId: {userId}</div>
      <div>title: {title}</div>
      <div>body: {body}</div>
    </div>
  );
};

export default VirtualizingItem;

// https://velog.io/@kimjh96/react-virtualized-%EB%A0%8C%EB%8D%94%EB%A7%81-%EC%84%B1%EB%8A%A5-%EC%B5%9C%EC%A0%81%ED%99%94
