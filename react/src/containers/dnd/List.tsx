import type { DropResult } from "react-beautiful-dnd";

import { useState } from "react";
import { DragDropContext, Droppable } from "react-beautiful-dnd";

import ListItem from "../../components/dnd/ListItem";

import { StyledList } from "../../components/_styledComponent";

interface ListItemType {
    id: string;
    name: string;
}

const List = () => {
    const LIST_ITEM: ListItemType[] = [
        { id: "I_can't", name: "123" },
        { id: "find_item", name: "qwe" },
        { id: "using_these_ids", name: "asd" },
        { id: "when_drag_end", name: "zxc" },
    ];

    const [items, setItems] = useState(LIST_ITEM);

    const onDragEnd = (result: DropResult) => {
        const { source, destination, draggableId } = result;
        if (source && destination) {
            const { index: srcIndex } = source;
            const { index: destIndex } = destination;

            if (srcIndex === destIndex) return;

            // setItems((prev: ListItemType[]) =>
            //     prev
            //         .filter((item: ListItemType) => item.id !== draggableId)
            //         .splice(destIndex, 0, { ...prev[srcIndex] })
            // );

            setItems((prev: ListItemType[]) => {
                const src = { ...prev[srcIndex] };
                const newList = prev.filter(
                    (item: ListItemType) => item.id !== draggableId
                );
                newList.splice(destIndex, 0, src);

                return newList;
            });
        }
    };

    return (
        <DragDropContext onDragEnd={onDragEnd}>
            <Droppable droppableId="droppable-section">
                {(provided) => (
                    <StyledList
                        {...provided.droppableProps}
                        ref={provided.innerRef}
                    >
                        {items.map((item: ListItemType, index: number) => (
                            <ListItem
                                key={item.id}
                                id={item.id}
                                name={item.name}
                                index={index}
                            />
                        ))}
                        {provided.placeholder}
                    </StyledList>
                )}
            </Droppable>
        </DragDropContext>
    );
};

export default List;
