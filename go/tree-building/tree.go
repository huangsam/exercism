package tree

import (
	"errors"
	"sort"
)

type Record struct {
	ID     int
	Parent int
}

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
	rootCount := 0
	for _, r := range records {
		if r.ID == 0 {
			rootCount += 1
		}
	}

	if count == 0 {
		return nil, nil
	} else if rootCount == 0 {
		return nil, errors.New("No root node exists")
	}

	adjacencyList := make(map[int][]int)
	for _, rec := range records {
		adjacencyList[rec.Parent] = append(adjacencyList[rec.Parent], rec.ID)
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
