package tree

import (
	"errors"
	"sort"
)

// Record has identifiers of its parent and itself
type Record struct {
	ID     int
	Parent int
}

// Node has identifier and children nodes
type Node struct {
	ID       int
	Children []*Node
}

func neighbors(adjacencyList map[int][]int, current int) []int {
	res, _ := adjacencyList[current]
	sort.Ints(res)
	return res
}

// Build constructs a Node that represents a tree of records
func Build(records []Record) (*Node, error) {
	count := len(records)
	if count == 0 {
		return nil, nil
	}

	adjacencyList := make(map[int][]int)
	noRoot := true
	for _, rec := range records {
		adjacencyList[rec.Parent] = append(adjacencyList[rec.Parent], rec.ID)
		if rec.ID == 0 {
			noRoot = false
		}
	}

	if noRoot {
		return nil, errors.New("No root node exists")
	}

	visited := make(map[int]bool)
	for i := 0; i < len(records); i++ {
		visited[i] = false
	}

	// Run BFS from root node to leaf nodes
	result := &Node{ID: 0}
	queue := []*Node{result}
	var curNode *Node
	var nxtNode *Node

	for len(queue) > 0 {
		curNode, queue = queue[0], queue[1:]

		for _, v := range neighbors(adjacencyList, curNode.ID) {
			if v > curNode.ID {
				nxtNode = &Node{ID: v}
				curNode.Children = append(curNode.Children, nxtNode)
				queue = append(queue, nxtNode)
			} else if v < curNode.ID {
				return nil, errors.New("Parent has higher ID than child")
			}
		}

		visited[curNode.ID] = true
	}

	for _, v := range visited {
		if !v {
			return nil, errors.New("At least one node was not visited")
		}
	}

	return result, nil
}
