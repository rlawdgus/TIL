import { type ComponentType } from "react";
import { type Post } from "../../App";
import { type ItemProps } from "../../components/virtualized/VirtualizingItem";

import { AutoSizer, CellMeasurer, CellMeasurerCache, List, ListRowProps, WindowScroller } from "react-virtualized";

const cache = new CellMeasurerCache({
  defaultWidth: 100,
  fixedWidth: true,
});

interface VirtualizedListProps {
  posts: Post[];
  Item: ComponentType<ItemProps>;
}

const VirtualizedList = ({ posts, Item }: VirtualizedListProps) => {
  const rowRenderer = ({ index, key, parent, style }: ListRowProps) => {
    const { id, userId, title, body } = posts[index];

    return (
      <CellMeasurer cache={cache} parent={parent} key={key} columnIndex={0} rowIndex={index}>
        <div style={style}>
          <Item index={index} id={id} userId={userId} title={title} body={body}/>
        </div>
      </CellMeasurer>
    );
  };

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
};

export default VirtualizedList;

// https://velog.io/@kimjh96/react-virtualized-%EB%A0%8C%EB%8D%94%EB%A7%81-%EC%84%B1%EB%8A%A5-%EC%B5%9C%EC%A0%81%ED%99%94
