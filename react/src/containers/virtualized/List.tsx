import { UIEventHandler, useState } from "react";

import Item from "../../components/virtualized/Item";

import { StyledList } from "../../components/virtualized/Item.style";

interface ListProps {
  list: number[];
  windowHeight: number;
  itemHeight: number;
}

const List = ({ list, windowHeight, itemHeight }: ListProps) => {
  const [scrollTop, setScrollTop] = useState(0);

  const { length } = list;
  const innerHeight = length * itemHeight;
  const startIndex = Math.floor(scrollTop / itemHeight);
  const endIndex = Math.min(
    length,
    Math.floor((scrollTop + windowHeight) / itemHeight) + 1
  );

  const sliced = [];
  for (let i = startIndex; i < endIndex; i++) {
    sliced.push(list[i]);
  }

  console.log(startIndex, endIndex);

  const onScroll: UIEventHandler<HTMLDivElement> = (e) =>
    setScrollTop(e.currentTarget.scrollTop);

  return (
    <div
      onScroll={onScroll}
      style={{ height: windowHeight, overflowY: "scroll" }}
    >
      <StyledList height={innerHeight}>
        {sliced.map((item, index) => (
          <Item
            key={index}
            value={item}
            height={itemHeight}
            offset={(index + startIndex) * itemHeight}
          />
        ))}
      </StyledList>
    </div>
  );
};

export default List;
