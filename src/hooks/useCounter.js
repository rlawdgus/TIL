import { useCallback } from 'react'
import { useDispatch, useSelector } from 'react-redux'

import { increaseAsync, decreaseAsync } from '../store/counter'

const useCounter = () =>{
    const num = useSelector(state => state.counter.num)
    const dispatch = useDispatch()
    const increase = useCallback(()=>{
        dispatch(increaseAsync(2));
    }, [dispatch])
    const decrease = useCallback(()=>{
        dispatch(decreaseAsync(2));
    }, [dispatch])
    return [num, increase, decrease];
}

export default useCounter;