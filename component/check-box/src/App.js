import React, { useState, useCallback, useEffect } from 'react'
import CheckBox from './components/CheckBox'
import CheckBoxList from './components/CheckBoxList'
import './scss/CheckBox.scss'

const App = () => {
    const [checkBoxes, setCheckBoxes] = useState([
        {
            id: 1,
            checked: false
        },
        {
            id: 2,
            checked: false
        },
        {
            id: 3,
            checked: false
        },
        {
            id: 4,
            checked: false
        },
        {
            id: 5,
            checked: false
        }
    ])

    const [checkAll, setCheckALL] = useState(false)

    const onClick = useCallback(id => {
        setCheckBoxes(checkBoxes.map(checkBox =>
            id === checkBox.id ? { ...checkBox, checked: !checkBox.checked } : checkBox
        ))
    }, [checkBoxes])

    const clickStateCheck = () => {
        const result = checkBoxes.reduce((prev, cur) => prev && cur.checked, true)
        setCheckALL(result)

        // const findResult = checkBoxes.find((checkBox) => !checkBox.checked)
        // setCheckAll(!findResult)

        // const findResult = checkBoxes.findIndex((checkBox) => !checkBox.checkd)
        // setCheckALL(findResult === -1)

    }

    useEffect(clickStateCheck, [checkBoxes])

    const onToggle = useCallback(() => {
        setCheckBoxes(checkBoxes.map(checkBox => {
            return { ...checkBox, checked: !checkAll }
        }))
    }, [checkAll, checkBoxes])

    return (
        <div className="contents">
            <CheckBox checked={checkAll} onClick={onToggle} />
            <CheckBoxList checkBoxes={checkBoxes} onClick={onClick} />
        </div>
    )
}

export default App